import sys
input = sys.stdin.readline

t=int(input())
for tests in range(t):
    n,k=map(int,input().split())
    A=list(map(int,input().split()))

    A.sort(reverse=True)

    ANS=1<<60

    for start in range(k+1):
        XCORE=0
        SCORE=0
        X=start
        for i in range(start,n):
            if X==0:
                SCORE+=A[i]
            else:
                XCORE+=A[i]//A[i-start]
                X-=1

        ANS=min(ANS,SCORE+XCORE)

    print(ANS)