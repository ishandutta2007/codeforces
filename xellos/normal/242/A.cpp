// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
// mylittlepony
using namespace std;
using namespace std::tr1;
	
int main() {
	int X,Y,A,B;
	scanf(" %d %d %d %d",&X,&Y,&A,&B);
	int ans =0;
	set< pair<int,int> > S;
	for(int i =A; i <= X; i++) for(int j =B; j <= Y; j++) if(i > j) S.insert(make_pair(i,j));
	printf("%d\n",(int)S.size());
	for(set< pair<int,int> >::iterator it =S.begin(); it != S.end(); it++) printf("%d %d\n",(*it).first,(*it).second);

	return 0;}
        
// look at my code
// my code is amazing