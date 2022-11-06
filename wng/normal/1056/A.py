n=[int(k) for k in raw_input().split(" ")][0]

a=None
for i in range(n):
    s=[int(k) for k in raw_input().split(" ")][1:]
    if a is None:
        a=set(s)
    else:
        a&=set(s)
print " ".join([str(k) for k in a])