s = input()
t = input()
vowel = "aeiou"
for i in range(len(s)):
    x = bool(s[i] in vowel)
    y = bool(t[i] in vowel)
    if x != y or len(s) != len(t):
        print("No")
        break
else:
    print("Yes")