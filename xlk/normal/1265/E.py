input();p,f=998244353,0
for i in map(int,input().split()):f=100*(f+1)*pow(i,p-2,p)%p
print(f)