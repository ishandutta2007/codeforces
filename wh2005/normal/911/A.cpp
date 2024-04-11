#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int n,a[100009],minn;
int main(){
	scanf("%d",&n);minn=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(minn==-1||a[i]<minn) minn=a[i];
	} 
	int ans=-1,pos=-1;
	for(int i=1;i<=n;i++){
		if(a[i]==minn){
			if(pos!=-1){
				if(i-pos<ans||ans==-1) ans=i-pos;
			}
			pos=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}