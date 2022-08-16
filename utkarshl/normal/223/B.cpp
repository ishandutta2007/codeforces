#include"stdio.h"
#include"algorithm"
#include"string.h"
using namespace std;
int main(){
	char a[300001],b[300001];
	scanf("%s%s",a,b);
	int n=strlen(a),m=strlen(b);
	int bestprefix[n],bestsuffix[n+1];
	int cur=0;
	for(int i=0;i<n;i++){
		if(a[i]==b[cur])cur++;
		bestprefix[i]=cur-1;
	}
	bestsuffix[n]=m;
	cur=m-1;
	for(int i=n-1;i>=0;i--){
		if(cur>=0 && a[i]==b[cur])cur--;
		bestsuffix[i]=cur+1;
	}
	int lastoccur[256];
	for(int i=0;i<256;i++)lastoccur[i]=-1;
	bool yes=1;
	for(int i=0;i<n;i++){
		if(bestprefix[i]>=0)lastoccur[b[bestprefix[i]]]=bestprefix[i];
		if(lastoccur[a[i]]<0 || lastoccur[a[i]]<bestsuffix[i+1]-1)yes=0;
		if(yes==0)break;
	}
	printf(yes?"Yes":"No");
}