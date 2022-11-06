n=[int(k) for k in raw_input().split(" ")][0]
a=[None]*3
a[0]=raw_input()
a[1]=raw_input()
a[2]=raw_input()
l=len(a[0])
b=[{} for i in range(3)]
for i in range(3):
    for k in a[i]:
        if k not in b[i]:
            b[i][k]=0
        b[i][k]+=1

res=[0]*3

for i in range(3):
    res[i]=max([min(k+n,l) if (k!=l or n!=1) else k-1 for k in b[i].values()])
    
ws=["Kuro","Shiro","Katie"]
winner="Draw"
for i in range(3):
    if res[i]>max(res[i-1],res[i-2]):
        winner=ws[i]

print winner