n=[int(k) for k in raw_input().split(" ")][0]
s=raw_input()

isok=False
for k in range(n-1):
    if s[k]!=s[k+1]:
        print "YES"
        print s[k:k+2]
        isok=True
        break
if not isok:
    print "NO"