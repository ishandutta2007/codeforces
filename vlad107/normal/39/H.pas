var
  i,j,k,b,o,l,p : longint;
  a : array [1..100,1..100] of longint;
  s : array [1..1000] of longint;
begin
  {assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  }readln(k);
  for i:=1 to 9 do
    for j:=1 to 9 do
      begin
        a[i,j]:=i*j;
      end;
  for i:=1 to k-1 do
    begin
    for j:=1 to k-1 do begin
        b:=a[i,j];
        o:=0;
        while b>= k do
          begin
            l:=b mod k;
            b:=b div k;
            inc(o);
            s[o]:=l;
          end;
        inc(o); s[o]:=b;
        for p:=o downto 1 do write(s[p]);
        Fillchar(s,sizeof(s),0);
        write(' ');
      end;
     writeln;
   end;
end.