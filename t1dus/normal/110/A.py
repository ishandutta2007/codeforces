s = input()
x = "47"
coun = s.count("4")
coun += s.count("7")
if coun == 4 or coun == 7:
    print("YES")
else:
    print("NO")