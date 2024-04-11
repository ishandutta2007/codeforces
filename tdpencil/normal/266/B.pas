Var n,t,i:longint;
   s:string;
   begin
     readln(n,t);
     readln(s);
     while t>0 do
      begin
       i:=1;
       while i<n do
         begin
           if (s[i]='B') and (s[i+1]='G') then begin
                                                  s[i]:='G';
                                                  s[i+1]:='B';
                                                  inc(i,2);
                                               end
                                               else inc(i);
         end;
         dec(t);
 
      end;
      writeln(s);
   end.