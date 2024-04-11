#[int(k) for k in raw_input().split(" ")]


n=int(raw_input())

ok=set([1,2])
isok=True
for i in range(n):
    wi=int(raw_input())
    if wi not in ok:
        isok=False
    else:
        loser=[k for k in ok if k!=wi][0]
        ok=set([1,2,3])
        ok.discard(loser)

if isok:
    print "YES"
else:
    print "NO"