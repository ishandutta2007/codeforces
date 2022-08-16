a = list(input())
try:
    a[0] = a[0].upper()
except:
    print()
else:
    print("".join(a))