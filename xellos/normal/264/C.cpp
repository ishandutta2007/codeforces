// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
// mylittlepony
using namespace std;
    
int main() {
    int N,Q;
    scanf(" %d %d",&N,&Q);
    vector< pair<int,int> > B(N);
    ALL_THE(B,it) scanf(" %d",&(it->first));
    ALL_THE(B,it) {
        scanf(" %d",&(it->second));
        it->second--;}
    
    vector< vector<int> > C(N);
    ALL_THE(B,it) C[it->second].push_back(it-B.begin());
    ALL_THE(C,it) (*it).push_back(N);

    for(int q =0; q < Q; q++) {
        int a,b;
        scanf(" %d %d",&a,&b);
        vector<long long> ans(N);
        for(int i =0; i < N; i++) ans[i] =(long long)B[i].first*(long long)b;

        vector<long long> V(N,-1000000000000000000);
        long long maxV =V[0], maxV2 =V[0];
        vector<int> isW(N,true);
        vector<int> W(N);
        for(int i =0; i < N; i++) W[i] =i;
        for(int i =0; i < N; i++) {
            ans[i] =max(ans[i],V[B[i].second]+(long long)B[i].first*(long long)a);
            if(W.size() == 1 && W[0] == B[i].second) ans[i] =max(ans[i],maxV2+(long long)B[i].first*(long long)b);
            else ans[i] =max(ans[i],maxV+(long long)B[i].first*(long long)b);
            if(ans[i] > maxV) {
                if(W.size() > 1 || !isW[B[i].second])maxV2 =maxV;
                ALL_THE(W,it) isW[*it] =false;
                W.clear();
                W.push_back(B[i].second);
                isW[B[i].second] =true;
                maxV =ans[i];
                V[B[i].second] =ans[i];}
            else if(ans[i] == maxV && V[B[i].second] < maxV) {
                W.push_back(B[i].second);
                isW[B[i].second] =true;}
            else if(ans[i] > maxV2 && !isW[B[i].second]) maxV2 =ans[i];
            V[B[i].second] =max(V[B[i].second],ans[i]);}
        long long ansR =0;
        ALL_THE(ans,it) {
//            printf("%d\n",*it);
            ansR =max(ansR,*it);}
        printf("%I64d\n",ansR);}
    return 0;}
        
// look at my code
// my code is amazing