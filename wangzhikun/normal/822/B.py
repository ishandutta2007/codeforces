x=input()
a=input()
b=input()
def dif(a,b):
    ans=0
    for i in range(len(a)):
        if a[i]!=b[i]:
            ans+=1
    return ans
fans = len(a)+1
fans2 = []
for i in range(len(b)-len(a)+1):
    if dif(b[i:i+len(a)],a) < fans:
        fans = dif(b[i:i+len(a)],a)
        fans2 = []
        d = b[i:i+len(a)]
        for i in range(len(a)):
            if a[i]!=d[i]:
                fans2.append(i+1)
print(fans)
for i in fans2:
    print(i,end = " ")