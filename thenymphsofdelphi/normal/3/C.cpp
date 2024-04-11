#include<bits/stdc++.h>
using namespace std;

vector<string> line(3, string());
int numx = 0, num0 = 0;

bool isfinish(char s){
	for (int i = 0; i < 3; i++){
		int j = 0;
		for (; j < 3; j++){
			if (line[i][j] != s){
			    break;
			}
		}
		if (j == 3){
		    return true;
		}
	}
	for (int i = 0; i < 3; i++){
		int j = 0;
		for (; j < 3; j++){
			if (line[j][i] != s){
			    break;
			}
		}
		if (j == 3){
		    return true;
		}
	}
	
	bool flag = true;
	for (int i = 0, j = 0; i < 3; i++, j++){
		if (line[i][j] != s){
		    flag = false;
		}
	}
	if (flag){
	    return true;
	}
	
	flag = true;
	for (int i = 2, j = 0; i >= 0; i--, j++){
		if (line[i][j] != s){
		    flag = false;
		}
	}
	if (flag){
	    return true;
	}
	
	return false;
}

int main(){
	for (int i = 0; i < 3; i++){
		cin >> line[i];
		for (int j = 0; j < line[i].size(); j++){
			if (line[i][j] == 'X'){
			    numx++;
			}
			if (line[i][j] == '0'){
			    num0++;
			}
		}
	}
	
	if (numx - num0 != 0 && numx - num0 != 1){
		cout << "illegal" << endl;
		return 0;
	}
	
	bool flag = isfinish('X');
	if (flag){
		if (numx - num0 == 1){
			cout << "the first player won" << endl;
		}
		else{
			cout << "illegal" << endl;
		}
		return 0;
	}
	
	flag = isfinish('0');
	if (flag){
		if (numx - num0 == 0){
			cout << "the second player won" << endl;
		}
		else{
			cout << "illegal" << endl;
		}
		return 0;
	}
	if (numx - num0 == 1 && numx + num0 < 9){
		cout << "second" << endl;
		return 0;
	}
	if (numx - num0 == 0 && numx + num0 < 9){
		cout << "first" << endl;
		return 0;
	}
	if (numx + num0 == 9){
		cout << "draw" << endl;
		return 0;
	}
	return 0;
}