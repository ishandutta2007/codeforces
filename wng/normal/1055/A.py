n,s=[int(k) for k in raw_input().split(" ")]
a=[int(k) for k in raw_input().split(" ")]
b=[int(k) for k in raw_input().split(" ")]
c=[a[k]*b[k] for k in range(n)]
d=[a[k]+b[k] for k in range(n)]

if a[0]:
    if a[s-1]:
        print "YES"
    else:
        if not b[s-1]:
            print "NO"
        else:
            cok=[k for k in range(n) if c[k]]
            if len(cok):
                maxc=max(cok)
                if maxc>s-1:
                    print "YES"
                else:
                    print "NO"
            else:
                print "NO"
else:
    print "NO"