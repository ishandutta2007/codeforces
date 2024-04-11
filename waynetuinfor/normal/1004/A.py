n, d = map(int, input().split())
a = list(map(int, input().split()))
s = set()
def check(x):
    global d
    mind = 10000000000
    for i in a:
        mind = min(mind, abs(i - x))
    return mind == d
for i in a:
    if check(i - d):
        s.add(i - d)
    if check(i + d):
        s.add(i + d)
print(len(s))