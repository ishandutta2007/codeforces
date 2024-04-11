//
//  main.cpp
//  TaskA
//
//  Created by Vlad Podtelkin on 20.01.14.
//  Copyright (c) 2014 Podtelkin Vladislav. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

long long t;
int r, q, n;

int main(int argc, const char * argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q);
        if (q == 1)
            r++;
        else
            t += r;
    }
    cout << t << endl;
    return 0;
}