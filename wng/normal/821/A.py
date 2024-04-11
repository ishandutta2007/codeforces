n=int(raw_input())
a=[0]*n
for i in range(n):
    a[i]=[int(k) for k in raw_input().split(" ")]
    
OK=True
for r in range(n):
    for c in range(n):
        if OK:
            if a[r][c]>1:
                arc=a[r][c]
                isrep=False
                row=a[r]
                col=[a[i][c] for i in range(n)]
                rowma=[arc-i for i in row]
                for i in rowma:
                    if i in col:
                        isrep=True
                if not isrep:
                    OK=False
        
print "Yes" if OK else "No"