//
//  main.cpp
//  
//
//  Created by Vlad Podtelkin on 17.01.14.
//  Copyright (c) 2014 Vlad Podtelkin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define N 500500

pair<int, int> a[N];
int n;

bool cmp(pair<int, int> x, pair<int, int> y) {
    return x > y;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a,a + n, cmp);
    printf("%d %d\n", a[0].second + 1, a[1].first);
    return 0;
}