n = int(raw_input())
l = [int(x) for x in raw_input().split()]
s = set()
for x in l:
    if x:
        s.add(x)
print len(s)