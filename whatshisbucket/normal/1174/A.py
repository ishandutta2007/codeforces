n=int(input())
a=list(map(int,input().split()))
if len(set(a))==1:
    print(-1)
else:
    a.sort()
    print(" ".join([str(guy) for guy in a]))