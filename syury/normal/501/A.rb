def max(x,y)
  if x>y
    return x
  else
    return y
  end
end

a,b,c,d = gets.split(" ").map {|x| x.to_i}

a = max(3*a/10,a-a/250*c)
b = max(3*b/10,b-b/250*d)
if a>b
  puts("Misha")
end
if a<b
  puts("Vasya")
end
if a==b
  puts("Tie")
end