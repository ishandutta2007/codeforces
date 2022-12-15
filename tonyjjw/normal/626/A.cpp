//*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 200+1;

int N;
char s[MN];
map<pii,int> m;

int main(){
	scanf("%d",&N);
	scanf("%s",s);
	int sx=0,sy=0;
	m[pii(0,0)]=1;
	int ans=0;
	for(int i=0;i<N;i++){
		if(s[i]=='U'){
			sx+=1;
		}
		else if(s[i]=='L'){
			sy+=1;
		}
		else if(s[i]=='R'){
			sy-=1;
		}
		else{
			sx-=1;
		}
		pii a = pii(sx,sy);
		ans+=m[a];
		m[a]=m[a]+1;
	}
	printf("%d\n",ans);
	return 0;
}

//*/