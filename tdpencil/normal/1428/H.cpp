#include <bits/stdc++.h>

using namespace std;

int queryRotation(int r, int d){ // Auxiliary function to print query and receive answer
	int res;
	cout << "? " << r << ' ' << d << endl << flush; 	// Print query
	cout.flush();
	cin >> res; 										// Get response
	if (res == -1) exit(1); 							// Error occured, exit immediately
	else return res; 									// Return result
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M; 				// Number of rings and number of sections per ring
	int totalPositions; 	// totalPositions = N*M
	int newNum; 
	int currentNum; 		// track the current number on the display (responses from interactor)
	int state = 0;			// 0 means searching for rings, 1 means finding the ring at this position
	int relpos[105] = {}; 		// Array to store the final relative positions

	cin >> N >> M;
	totalPositions = N*M;

	// While this statement doesn't do anything, 
	// it serves as a reminder that we are taking 
	// the initial starting position of ring 0 
	// to be position 0
	relpos[0] = 0; 
	
	currentNum = queryRotation(0,1);
	relpos[0] = (relpos[0] + 1) % totalPositions;
	

	// Now we prepare the set of unknown rings S
	vector<int> S;
	for (int i = 1; i < N; ++i){
		S.push_back(i);
	}

	// We now perform a preliminary rotation of ring 0 around until 
	// we are certain that ring 0 coincides with another ring 
	// at its leftmost point and the section to its left is empty

	// This occurs when the difference changes from increasing when 
	// ring 0 moves right to non-increasing when ring 0
	// moves right
	int hasIncreased = 0; 
	while (1){
		// Rotate once, get the new number
		newNum = queryRotation(0,1);
		relpos[0] = (relpos[0] + 1) % totalPositions;
		// Check if the number has increased		
		if (newNum > currentNum){
			hasIncreased = 1;	
			currentNum = newNum;
		} 	
		else{ // Otherwise the number hasn't increased		
			currentNum = newNum;
			// Check if we have increased before
			if (hasIncreased){ 

				// If we have, it means that our previous position 
				// coincided with the left endpoint of another arc
				// Time to begin the detection stage
				state = 1;
				currentNum = queryRotation(0,-1);
				relpos[0] = (relpos[0] - 1 + totalPositions) % totalPositions;
				break;
			}							
		}
		
	}
	
	while (!S.empty()){ // While we haven't found all of the rings yet
		if (state == 1){ // If we are searching for an arc here
			int curArc = 0; // to store the new arc

			vector<int> T = S;	// set of candiate arcs
			vector<int> F;		// set of arcs that have been moved left

			for (int i = 0; i < T.size()/2; ++i){ // take the smaller half
				F.push_back(T[i]);
				currentNum = queryRotation(T[i],-1);
			}

			while (T.size() > 1){ // while the number of candidate arcs is > 1, we binary search on the remaining arcs
				int newNum = queryRotation(0,-1);
				relpos[0] = (relpos[0] - 1 + totalPositions) % totalPositions;
				if (newNum >= currentNum){ // the arc that we are looking for lies in F

					// Set T to F
					T.clear();
					for (auto it : F){
					    T.push_back(it);
					}	

					// Half the size of F by moving the smaller half to the right							
					int sz = F.size()/2;
					for (int i = 0; i < sz; ++i){
						int revRing = F.back();
						currentNum = queryRotation(revRing,1);
						F.pop_back();
					}

				}
				else{ // the arc we are looking for does not lie in F
					vector<int> temp;
					for (auto it1 : T){
					    int check = 0;
					    for (auto it2 : F){
					        if (it1 == it2) check = 1;
					    }
					    if (!check) temp.push_back(it1);
					}
					T = temp;
					F.clear();
					for (int i = 0; i < T.size()/2; ++i){ // take the smaller half once again
						currentNum = queryRotation(T[i],-1);
						F.push_back(T[i]);
					}
				}	
				currentNum = queryRotation(0,1); // bring arc 0 back
				relpos[0] = (relpos[0] + 1) % totalPositions;
			}
            
			curArc = T[0]; // we have found the arc
			

			// we want this arc to be M+1 sections away from the current position 
			// of arc 0 so that it does not interfere with later searches

			if (!F.empty()){ // the arc we found still lies in F
				for (int i = 0; i < M; ++i){ // move the arc back by M sections
					currentNum = queryRotation(curArc,-1);
				}
				relpos[curArc] = relpos[0] - M - 1;
			}
			else{ // the arc we found does not lie in F
				for (int i = 0; i <= M; ++i){ // move the arc back by M+1 sections
					currentNum = queryRotation(curArc,-1);
				}
				relpos[curArc] = relpos[0] - M - 1;
			}
			// We now remove curArc from S
			vector<int> temp;
			for (auto it : S){
				if (it != curArc) temp.push_back(it); 
			}
			S.clear();
			for (auto it : temp) S.push_back(it);
			
			
			state = 0;
			currentNum = queryRotation(0,-1);
			relpos[0] = (relpos[0] - 1 + totalPositions) % totalPositions;
			hasIncreased = 0;
		}
		else{ // keep moving right
		    
			newNum = queryRotation(0,1);
			relpos[0] = (relpos[0] + 1) % totalPositions;
			if (newNum <= currentNum && hasIncreased == 1){ // start searching
				newNum = queryRotation(0,-1);
				relpos[0] = (relpos[0] - 1 + totalPositions) % totalPositions;
				state = 1;
			}
			else if (newNum > currentNum) hasIncreased = 1;
			currentNum = newNum;
		}

	}
	cout << "! ";
	for (int i = 1; i < N; ++i){
		cout << (((relpos[i] - relpos[0] + 5 * totalPositions)%totalPositions) + totalPositions) % totalPositions << ' ';
	}
	cout << endl << flush;

}