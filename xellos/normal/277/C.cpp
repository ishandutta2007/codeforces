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
#define chocolate win
// mylittlepony
using namespace std;
    
int main() {
    int N,M,K,a,b,c,d;
    cin >> N >> M >> K;
    
    vector< pair< int, pair<int,int> > > cvod;
    vector< pair< int, pair<int,int> > > czv;
    map<int,int> usv;
    map<int,int> usz;
    for(int i =0; i < K; i++) {
        scanf(" %d %d %d %d",&a,&b,&c,&d);
        if(a == c) {
            if(b > d) swap(b,d);
            czv.push_back(make_pair(--a,make_pair(b,d)));
            usz[a] =0;}
        else {
            if(a > c) swap(a,c);
            cvod.push_back(make_pair(--b,make_pair(a,c)));
            usv[b] =0;}}

    a =0;
    ALL_THE(usv,it) {
        it->second =a;
        a++;}
    a =0;
    ALL_THE(usz,it) {
        it->second =a;
        a++;}

    int SG =0, cutxa =-1, cutxb =-1, cutya =-1, cutyb =-1;
    if((M-usv.size())%2 == 0) SG =SG^N;
    if((N-usz.size())%2 == 0) SG =SG^M;
        
    sort(czv.begin(),czv.end());
    sort(cvod.begin(),cvod.end());
    int N0 =N, M0 =M;
    M =usv.size();
    N =usz.size();
    
    vector< vector< pair<int,int> > > Cvod(M);
    for(int i =0; i < cvod.size(); i++) Cvod[usv[cvod[i].first]].push_back(cvod[i].second);
    for(int i =0; i < M; i++) {
        a =b =c =0;
        for(int j =0; j < Cvod[i].size(); j++) {
            a +=max(0,Cvod[i][j].first-b);
            b =max(b,Cvod[i][j].second);
            c =Cvod[i][j].first;}
        a +=N0-b;
        SG =SG^a;}
    
    vector< vector< pair<int,int> > > Czv(N);
    for(int i =0; i < czv.size(); i++) Czv[usz[czv[i].first]].push_back(czv[i].second);
    for(int i =0; i < N; i++) {
        a =b =c =0;
        for(int j =0; j < Czv[i].size(); j++) {
            a +=max(0,Czv[i][j].first-b);
            b =max(b,Czv[i][j].second);
            c =Czv[i][j].first;}
        a +=M0-b;
        SG =SG^a;}
    
    if(SG == 0) printf("SECOND\n");
    else {
        printf("FIRST\n");
        a =usv.size();
        usv[M0-1] =a;
        if((N0^SG) < N0) ALL_THE(usv,it) if(it->first != it->second) {
            cutya =cutyb =it->first;
            cutxa =0, cutxb =N0-(N0^SG);
            break;}
        a =usz.size();
        usz[N0-1] =a;
        if((M0^SG) < M0) ALL_THE(usz,it) if(it->first != it->second) {
            cutxa =cutxb =it->first;
            cutya =0, cutyb =M0-(M0^SG);
            break;}
        for(int i =0; i < M; i++) {
            a =b =c =0;
            for(int j =0; j < Cvod[i].size(); j++) {
                a +=max(0,Cvod[i][j].first-b);
                b =max(b,Cvod[i][j].second);
                c =Cvod[i][j].first;}
            a +=N0-b;
            if((a^SG) < a && cutxa == -1) {
                ALL_THE(usv,it) 
                    if(it->second == i) cutya =cutyb =it->first+1;
                SG =a-(a^SG); // reduce by SG
                cutxa =a =b =c =0;
                for(int j =0; j < Cvod[i].size(); j++) {
                    a +=max(0,Cvod[i][j].first-b);
                    b =max(b,Cvod[i][j].second);
                    c =Cvod[i][j].first;
                    if(a >= SG && cutxb == -1) cutxb =c-(a-SG);}
                a +=N0-b;
                if(a >= SG && cutxb == -1) cutxb =N0-(a-SG);}
            }
        for(int i =0; i < N; i++) {
            a =b =c =0;
            for(int j =0; j < Czv[i].size(); j++) {
                a +=max(0,Czv[i][j].first-b);
                b =max(b,Czv[i][j].second);
                c =Czv[i][j].first;}
            a +=M0-b;
            if((a^SG) < a && cutxa == -1) {
                ALL_THE(usz,it) if(it->second == i) cutxa =cutxb =it->first+1;
                SG =a-(a^SG);
                cutya =a =b =c =0;
                for(int j =0; j < Czv[i].size(); j++) {
                    a +=max(0,Czv[i][j].first-b);
                    b =max(b,Czv[i][j].second);
                    c =Czv[i][j].first;
                    if(a >= SG && cutyb == -1) cutyb =c-(a-SG);}
                a +=M0-b;
                if(a >= SG && cutyb == -1) cutyb =M0-(a-SG);}
            }
        cout << cutxa << " " << cutya << " " << cutxb << " " << cutyb << endl;}
    return 0;}
        
// look at my code
// my code is amazing