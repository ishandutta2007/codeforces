a = input()
dang = False
x = 0
y = 0
for i in a:
      if i == "0":
            x += 1
            y = 0
      if i == "1":
            y += 1
            x = 0
      if x == 7 or y == 7:
            print("YES")
            break
else:
      print("NO")