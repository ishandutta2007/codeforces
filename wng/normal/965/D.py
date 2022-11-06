w,l=[int(k) for k in raw_input().split(" ")]
inf=10**9
a=[inf]+[int(k) for k in raw_input().split(" ")]+[inf]

qualif=[inf]+[0]*w
fulluntil=0
for k in range(0,w):
    if qualif[k]:
        j=max(k+1,fulluntil+1)
        while j<=min(w,k+l) and qualif[k]:
            if a[j]-qualif[j]:
                transf=min(qualif[k],a[j]-qualif[j])
                qualif[k]-=transf
                qualif[j]+=transf
                if qualif[j]==a[j]:
                    fulluntil=j
            else:
                fulluntil=j
            j+=1

print qualif[w]