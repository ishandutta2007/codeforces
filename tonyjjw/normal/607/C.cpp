#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 1000000+10;

int N,fail[MN];
char buf1[MN],buf2[MN];

char r(char c){
	if(c=='N')return 'S';
	if(c=='S')return 'N';
	if(c=='E')return 'W';
	if(c=='W')return 'E';
}

int main(){
	int TC;
	TC=1;
	for(int tc=1;tc<=TC;tc++){
		scanf("%d",&N); N--;
		scanf("%s%s",buf1,buf2);
		reverse(buf2,buf2+N);
		for(int i=0;i<N;i++) buf2[i]=r(buf2[i]);
		fail[0]=-1;
		for(int i=1;i<N;i++){
			int k=fail[i-1];
			while(k!=-1 && buf2[k+1]!=buf2[i]) k=fail[k];
			if(buf2[k+1]==buf2[i]) k++;
			fail[i]=k;
		}
		bool no = false;
		for(int i=0,j=-1;i<N;i++){
			while(j!=-1 && buf1[i]!=buf2[j+1]) j=fail[j];
			if(buf1[i]==buf2[j+1]){
				if(i==N-1){
					no = true;
				}
				j++;
				continue;
			}
		}
		if(no) puts("NO");
		else puts("YES");
	}
	return 0;
}