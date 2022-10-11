n = int(raw_input())
if n%10 > 5:
    n += (10 - (n%10))
else:
    n -= n%10
print n