var
  re,a:array[1..15]of longint;
  t:array[1..15]of string;
  x,i,j,kr,n:longint;
  found:boolean;
  procedure rec(x:longint);
    var
      i,j:longint;
    begin
      if (x-2>=kr)then exit;
      if (a[x-1]>n)then exit;
      if (a[x-1]=n)then begin
        kr:=x-2;
        re:=a;
        exit;
      end;
      for i:=1 to x-1 do begin
        a[x]:=2*a[i];
        rec(x+1);
        a[x]:=4*a[i];
        rec(x+1);
        a[x]:=8*a[i];
        rec(x+1);
      end;
      for i:=1 to x-1 do 
        for j:=1 to x-1 do begin
          a[x]:=a[i]+a[j];
          rec(x+1);
          a[x]:=a[i]+2*a[j];
          rec(x+1);
          a[x]:=a[i]+4*a[j];
          rec(x+1);
          a[x]:=a[i]+8*a[j];
          rec(x+1);
        end;
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n);
  a[1]:=1;
  kr:=6;
  rec(2);
  writeln(kr);
  a:=re;
  for i:=1 to 26 do t[i]:='e'+chr(i+96)+'x';
  for x:=2 to kr+1 do begin
    write('lea ',t[x],', [');
    found:=false;
    for i:=1 to x-1 do begin 
      if (found)then break;
      if (a[i]=a[x])then begin
        found:=true;
        writeln(t[i],']');
        break;
      end;
      if (a[i]*2=a[x])then begin
        found:=true;
        writeln('2*',t[i],']');
        break;
      end;
      if (a[i]*4=a[x])then begin
        found:=true;
        writeln('4*',t[i],']');
        break;
      end;
      if (a[i]*8=a[x])then begin
        found:=true;
        writeln('8*',t[i],']');
        break;
      end;
    end;
    for i:=1 to x-1 do 
      for j:=1 to x-1 do begin
        if (found)then break;
        if (a[i]+a[j]=a[x])then begin
          found:=true;
          writeln(t[i],' + ',t[j],']');
          break;
        end;
        if (a[i]+2*a[j]=a[x])then begin
          found:=true;
          writeln(t[i],' + 2*',t[j],']');
          break;
        end;
        if (a[i]+4*a[j]=a[x])then begin
          found:=true;
          writeln(t[i],' + 4*',t[j],']');          
          break;
        end;
        if (a[i]+8*a[j]=a[x])then begin
          found:=true;
          writeln(t[i],' + 8*',t[j],']');          
          break;
        end;
      end;
  end;
  close(output);close(input);
end.