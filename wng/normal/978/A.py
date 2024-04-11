#978a
n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]

s=set()
res=[]
for i in a[::-1]:
    if i not in s:
        s.add(i)
        res+=[str(i)]

print len(res)
print " ".join(res[::-1])