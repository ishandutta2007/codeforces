
t=[int(k) for k in raw_input().split(" ")]


s=sum(t)
ok=False
for i in range(6):
    for j in range(i+1,6):
        for k in range(j+1,6):
            if (t[i]+t[j]+t[k])*2==s:
                ok=True
                break
            
print "YES" if ok else "NO"