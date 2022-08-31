coun = 0
for i in range(int(input())):
      x = input().replace("X","")
      if x == "++":
            coun += 1
      else:
            coun -= 1
print(coun)