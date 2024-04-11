Var
   t : Array[1..6]of String;
   i,j,conv,maxconv,maxi,maxj: Integer;
Begin
   maxconv:=-1;
   for i:=1 to 6 do
   begin
      Readln(t[i]);
      for j:=1 to 8 do
      begin
         conv:=(8-i) div 2;
         if (j=3) or (j=6) then continue;
         if (3<j) and (j<6) then Inc(conv);
         if (t[i][j]='.') and (conv>maxconv) then
         begin
            maxconv:=conv;maxi:=i;maxj:=j;
         end;
      end;
   end;
   t[maxi][maxj]:='P';
   for i:=1 to 6 do writeln(t[i]);
End.