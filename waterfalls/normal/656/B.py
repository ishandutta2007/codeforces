from fractions import gcd

n = int(input())
m = list(map(int,input().split()))
r = list(map(int,input().split()))
tot = 1
for i in m:
    tot = tot*i//gcd(tot,i)
has = [0]*tot
for i in range(n):
    on = r[i]
    while on<tot:
        has[on] = 1
        on+=m[i]
print(sum(has)/tot)