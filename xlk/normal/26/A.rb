require'prime'
p 1.upto(gets.to_i).count{|i|Prime.prime_division(i).size==2}