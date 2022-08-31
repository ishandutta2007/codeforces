#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,K,q,num[1210000],pd[210000];
struct ask{
    int x1,y1,x2,y2,where;
    void scan(){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    }
}A[210000];
struct atom{
    int x,y;
}x[210000];
int compare(atom k1,atom k2){
    return k1.x>k2.x;
}
int compare2(atom k1,atom k2){
    return k1.y>k2.y;
}
int compare3(ask k1,ask k2){
    return k1.x1>k2.x1;
}
int compare4(ask k1,ask k2){
    return k1.y1>k2.y1;
}
void insert(int k1,int k2,int k3,int k4,int k5){
    if (k2==k3){
        num[k1]=min(num[k1],k5); return;
    }
    int mid=k2+k3>>1;
    if (mid>=k4) insert(k1*2,k2,mid,k4,k5); else insert(k1*2+1,mid+1,k3,k4,k5);
    num[k1]=max(num[k1*2],num[k1*2+1]);
}
int find(int k1,int k2,int k3,int k4,int k5){
    if (k2>k5||k3<k4) return 0;
    if (k2>=k4&&k3<=k5) return num[k1];
    int mid=k2+k3>>1;
    return max(find(k1*2,k2,mid,k4,k5),find(k1*2+1,mid+1,k3,k4,k5));
}
int main(){
    scanf("%d%d%d%d",&n,&m,&K,&q);
    for (int i=1;i<=K;i++){
        scanf("%d",&x[i].x); scanf("%d",&x[i].y);
    }
    for (int i=1;i<=q;i++){
        A[i].scan(); A[i].where=i;
    }
    for (int i=1;i<=q;i++) pd[i]=1;
    sort(x+1,x+K+1,compare);
    sort(A+1,A+q+1,compare3);
    memset(num,0x3f,sizeof num);
    int now=1;
    for (int i=1;i<=q;i++){
        while (now<=K&&x[now].x>=A[i].x1) {insert(1,1,m,x[now].y,x[now].x); now++;}
        if (find(1,1,m,A[i].y1,A[i].y2)<=A[i].x2) pd[A[i].where]=0;
    }
    sort(x+1,x+K+1,compare2);
    sort(A+1,A+q+1,compare4);
    memset(num,0x3f,sizeof num);
    now=1;
    for (int i=1;i<=q;i++){
        while (now<=K&&x[now].y>=A[i].y1) {insert(1,1,n,x[now].x,x[now].y); now++;}
        if (find(1,1,n,A[i].x1,A[i].x2)<=A[i].y2) pd[A[i].where]=0; 
    }
    for (int i=1;i<=q;i++) if (pd[i]==0) printf("YES\n"); else printf("NO\n");
    return 0;
}