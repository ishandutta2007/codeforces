#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 3e5+5;
int T, N, K, i, j, arr[MN], fl;
string s;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&K);
		cin >> s; fl = 0;
		for(i=0;i<K;i++) arr[i]=-1;
		for(i=0;i<N;i++){
			if(s[i]=='0'){
				if(arr[i%K]==1){
					fl = 1;
					break;
				}
				else arr[i%K] = 0;
			}
			else if(s[i]=='1'){
				if(arr[i%K]==0){
					fl = 1;
					break;
				}
				else arr[i%K]=1;
			}
		}
		int cnt0 = 0, cnt1 = 0;
		for(i=0;i<K;i++){
			if(arr[i]==0) cnt0++;
			else if(arr[i]==1) cnt1++;
		}
		if(2*cnt0>K||2*cnt1>K) fl = 1;
		if(fl) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}