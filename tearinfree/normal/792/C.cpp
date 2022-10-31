#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> ip;

char str[100010];
int arr[100010];
int n;

int check(vector<int> &a,int del) {
	if(a.size()<del) return -1;

	int cnt=del,zf=0;
	for(int i=0;i<n;i++) {
		if(del==2) {
			if(i==a[a.size()-2] || i==a[a.size()-1]) continue;
			else if(arr[i]==0 && i!=n-1) {
				zf=1;
				cnt++;
				continue;
			}
			else break;
		}
		else {
			if(i==a[a.size()-1]) continue;
			else if(arr[i]==0 && i!=n-1) {
				zf=1;
				cnt++;
				continue;
			}
			else break;
		}
	}
	if(cnt==n && !zf) return -1;
	if(cnt==n && zf) return n-1;
	return cnt;
}
void trace(vector<int> &a,int del,int c) {
	if(c==n-1) {
		for(int i=0;i<n;i++) {
			if(del==2) {
				if(i!=a[a.size()-2] && i!=a[a.size()-1] && arr[i]%3==0){
					printf("%d",arr[i]);
					break;
				}
			}
			else {
				if(i!=a[a.size()-1] && arr[i]%3==0){
					printf("%d",arr[i]);
					break;
				}
			}
		}
		return;
	}
	int flag=0;
	for(int i=0;i<n;i++) {
		if(del==2) {
			if(i==a[a.size()-2] || i==a[a.size()-1]) continue;
			else if(arr[i]==0 && i!=n-1 && !flag) {
				continue;
			}
			else {
				printf("%d",arr[i]);flag=1;
			}
		}
		else {
			if(i==a[a.size()-1]) continue;
			else if(arr[i]==0 && i!=n-1 && !flag) {
				continue;
			}
			else {
				printf("%d",arr[i]);flag=1;
			}
		}
	}
}
int main() {
	scanf("%s",str);
	n=strlen(str);
	
	vector<int> r1,r2;

	int a=0;
	for(int i=0;i<n;i++) {
		arr[i]=str[i]-'0';
		a=(a+arr[i])%3;
		if(arr[i]%3==1) r1.push_back(i);
		else if(arr[i]%3==2) r2.push_back(i);
	}

	int mx=-1,val,id;
	if(a==0) {
		for(int i=0;i<n;i++)printf("%d",arr[i]);
		return 0;
	}
	else if(a==1) {
		val=check(r1,1);
		if(val!=-1) {
			if(mx==-1) mx=val,id=1;
			else if(mx>val) mx=val,id=1;
		}
		
		val=check(r2,2);
		if(val!=-1) {
			if(mx==-1) mx=val,id=2;
			else if(mx>val) mx=val,id=2;
		}
	}
	else {
		val=check(r1,2);
		if(val!=-1) {
			if(mx==-1) mx=val,id=1;
			else if(mx>val) mx=val,id=1;
		}
		
		val=check(r2,1);
		if(val!=-1) {
			if(mx==-1) mx=val,id=2;
			else if(mx>val) mx=val,id=2;
		}
	}

	if(mx==-1) printf("-1");
	else {
		if(a==1){
			if(id==1) trace(r1,1,mx);
			else trace(r2,2,mx);
		}
		else {
			if(id==1) trace(r1,2,mx);
			else trace(r2,1,mx);
		}
	}

	return 0;
}