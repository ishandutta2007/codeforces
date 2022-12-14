// ...
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	int last=-1, count{};
	int countOne{}, lastLarge=-1;
	bool goodSegment=false;
	int result{};
	for(int _=0; _<=number; ++_){
		int value;
		if(_<number) std::cin>>value; else value=-2;
		if(value==last)
			++count;
		else{
			if(count!=0){ // process (last, count)
				if(count==1){ // process (last x1)
					assert(countOne>=0);
					if(countOne%2!=0 and last!=lastLarge){
						goodSegment=true;
					}

					countOne++;
				}else{
					{ // process: <lastLarge(x >1), last (x count>1) > contain :countOne:
						result+=countOne+2;
						if(lastLarge==last and not goodSegment) {
							assert(countOne%2==1); assert(countOne>0);
							--result;
						}
					}

					countOne=0;
					assert(count>1);
					lastLarge=last;
					goodSegment=false;
				}
			}
			last=value;
			count=1;
		}
	}
	result+=countOne; // without +2, this is the last
	std::cout<<result<<'\n';
}