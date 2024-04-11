w,h=map(int,input().split())
tot=1
for i in range(w+h):
    tot=(2*tot)%998244353
print(tot)