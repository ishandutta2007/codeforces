#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;
typedef long long lli;

int n;
char str[1000100];
int arr[26],tmp[26],sel[26];

int main() {
	scanf("%d",&n);
	for(int i=0;i<26;i++) arr[i]=1;
	int res=0,flag=0,c=26;
	char t;

	for(int i=0;i<n;i++) {
		scanf(" %c %s",&t,str);
		int l=strlen(str);
		if(t=='!') {
			if(flag) res++;
			for(int i=0;i<26;i++) tmp[i]=0;
			for(int i=0;i<l;i++) tmp[str[i]-'a']=1;
			for(int i=0;i<26;i++) if(tmp[i]==0) {
				if(arr[i]==1) {
					c--;
					if(c==1) flag=1;
				}
				arr[i]=0;
			}
		}
		else if(t=='.') {
			for(int i=0;i<l;i++) {
				if(arr[str[i]-'a']==1) {
					c--;
					if(c==1) flag=1;
				}
				arr[str[i]-'a']=0;
			}
		}
		else {
			if(flag && arr[str[0]-'a']!=1) {
				res++;
			}
			if(!flag && arr[str[0]-'a']==1) {
				c--;
				if(c==1) flag=1;
				arr[str[0]-'a']=0;
			}
		}
	}
	printf("%d\n",res);
	return 0;
}