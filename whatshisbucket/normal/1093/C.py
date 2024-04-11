n=int(input())
a=list(map(int,input().split()))
backlist=[a[0]]
listy=[0]
for i in range(n//2-1):
    mini=max(listy[-1],a[i+1]-backlist[-1])
    listy.append(mini)
    backlist.append(a[i+1]-mini)
full=listy+backlist[::-1]
out=""
for i in range(n):
    out+=str(full[i])+" "
print(out[:-1])