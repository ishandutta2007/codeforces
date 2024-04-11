#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n;

long long k;

vector<long long> v;


// checks whether the number of given operations is sufficient

// to raise the median of the array to x

bool check(long long x){

    long long operationsNeeded = 0;

    for(int i = (n-1)/2; i < n; i++){

        operationsNeeded += max(0LL, x-v[i]);

    }

    return operationsNeeded <= k;

}


// binary searches for the correct answer

long long search(){

    long long pos = 0; long long max = 2E9;

    for(long long a = max; a >= 1; a /= 2){

        while(check(pos+a)) pos += a;

    }

    return pos;

}


int main() {

    cin >> n >> k;

    for(int i = 0; i < n; i++){

        int t;

        cin >> t;

        v.push_back(t);

    }

    sort(v.begin(), v.end());


    cout << search() << '\n';

}