s = raw_input()
print ['NO', 'YES'][sum(s.count(i) for i in ["Danil", "Olya", "Slava", "Ann", "Nikita"]) == 1]