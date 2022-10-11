n = int(raw_input())
l = raw_input()
t = [int(x) for x in l.split()]
odd = 0
for x in t:
    if x%2 == 1:
        odd += 1
print "First" if odd else "Second"