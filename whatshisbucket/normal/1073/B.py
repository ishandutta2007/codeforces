n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ha={}
for i in range(n):
    ha[a[i]]=i
removed=0
out=""
for i in range(n):
    if ha[b[i]]<removed:
        out+="0 "
    else:
        out+=str(ha[b[i]]-removed+1)+" "
        removed=ha[b[i]]+1
print(out[:-1])