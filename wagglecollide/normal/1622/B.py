import sys
input = sys.stdin.readline

t=int(input())
for tests in range(t):
    n=int(input())
    P=list(map(int,input().split()))
    S=input().strip()

    ALL=[]
    SUB=[]

    for i in range(n):
        if S[i]=="0":
            ALL.append(i)
        else:
            SUB.append(i)

    ALL.sort(key=lambda x:P[x])
    SUB.sort(key=lambda x:P[x])

    #print(ALL)
    #print(SUB)

    ANS=[-1]*n

    for i in range(len(ALL)):
        ANS[ALL[i]]=i+1

    for i in range(len(SUB)):
        ANS[SUB[i]]=i+1+len(ALL)

    print(*ANS)