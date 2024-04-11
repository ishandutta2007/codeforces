#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
queue<int>Q1,Q2;
vector<int>A[210000];
char ch[210000];
int n;
int main(){
	scanf("%s",ch+1); n=strlen(ch+1);
	int num=0;
	for (int i=1;i<=n;i++) if (ch[i]=='1') num--; else num++;
	if (num<=0){
		printf("-1\n"); return 0;
	}
	//cout<<num<<endl;
	for (int i=1;i<=num;i++) Q2.push(i);
	for (int i=1;i<=n;i++)
		if (ch[i]=='1'){
			if (Q1.empty()){
				printf("-1\n"); return 0;
			}
			int num=Q1.front(); Q1.pop(); Q2.push(num);
			A[num].push_back(i);
		} else {
			if (Q2.empty()){
				printf("-1\n"); return 0;
			}
			int num=Q2.front(); Q2.pop(); Q1.push(num);
			A[num].push_back(i);
		}
	if (!Q2.empty()){
		printf("-1\n"); return 0;
	}
	printf("%d\n",num);
	for (int i=1;i<=num;i++){
		printf("%d",(int)(A[i].size()));
		for (int j=0;j<A[i].size();j++) printf(" %d",A[i][j]);
		puts("");
	}
}