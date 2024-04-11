t=int(input())
for u in range(t):
    a,b,k=map(int,input().split())
    tot=(a-b)*(k//2)
    tot+=a*(k%2)
    print(tot)