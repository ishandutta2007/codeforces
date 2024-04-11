l=int(input())
s=input()

res=10**l
lg=l//2
while lg>0 and s[lg]=="0":
    lg-=1
ld=l//2+1
while ld<l and s[ld]=="0":
    ld+=1
for lt in [lg,lg-1,ld,ld+1]:
    if (lt>0 and lt<l):
        if s[lt]!="0":
            res=min(res,int(s[:lt])+int(s[lt:]))
print(res)