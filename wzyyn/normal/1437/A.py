T=int(input())
for Tid in range(T):
    l,r=map(int,input().split())
    if l*2>r:
        print('YES')
    else:
        print('NO')