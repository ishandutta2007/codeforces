
#978d

n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]

ok=False
minres=10000000
for i in range(a[0]-1,a[0]+2):
    for j in range(a[-1]-1,a[-1]+2):
        mr=0
        ook=True
        if n>1 and not (j-i)%(n-1):
            for k in range(n):
                if abs(i+(j-i)*k/(n-1)-a[k])<2:
                    if abs(i+(j-i)*k/(n-1)-a[k]):
                        mr+=1
                else:
                    ook=False
                    break
            if ook:
                ok=True
                minres=min(mr,minres)
               # if mr==minres:
                #    print mr, i,j
        elif n==1:
            ok=True
            minres=0
        
if not ok:
    minres=-1
print minres