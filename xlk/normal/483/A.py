l, r = map(int, raw_input().split())
l += l % 2
if l + 2 > r:
        print -1
else:
        print l, l + 1, l + 2