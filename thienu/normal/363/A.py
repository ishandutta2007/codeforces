a = "OO|OOOOO"
s = input()
for c in reversed(s):
    c = int(c)
    x = list(a)
    if c >= 5:
        x[0] = "-"
    else:
        x[1] = "-"
    x[3+c%5] = "-"
    print("".join(x))