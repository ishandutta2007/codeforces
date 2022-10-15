s = input()
x = int(input())
if s == "ABC":
    print("YES" if x < 2000 else "NO")
elif s == "ARC":
    print("YES" if x < 2800 else "NO")
elif s == "AGC":
    print("YES" if x >= 1200 else "NO")
else:
    print("YES")