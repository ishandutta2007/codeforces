$n=<>;
for(1..$n){
   $d=<>;
   $delta=$d*($d-4);
   if ($delta<0){print "N\n";next;}
   print("Y ",($d+sqrt $delta)/2,' ',($d -sqrt $delta)/2,"\n");
}