using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace CF_39A
{
	class Program
	{
		public class pair:IComparable
		{
			public int x,y;
			public int CompareTo(object A)
			{
				pair a = A as pair;
				return x == a.x ? y.CompareTo(a.y) : x.CompareTo(a.x);
			}
		}
		static void Main(string[] args)
		{
			int a = int.Parse(Console.ReadLine());
			String s = Console.ReadLine();
			var q=Regex.Matches(s,@"((\+|-)?(\d*))(\*)?(a\+\+|\+\+a)");
			List<pair>u=new List<pair>();
			foreach(Match i in q)
			{
				pair p = new pair();
				String w = i.Groups[1].ToString();
				if (w.Equals("+") || w.Equals("-") || w.Equals(""))
					w += "1";
				p.x = int.Parse(w);
				if (i.Value.EndsWith("a"))
					p.y = 1;
				else
					p.y = 0;
				u.Add(p);
			}
			u.Sort();
			int z = 0;
			foreach (pair i in u)
				z += i.y==1 ? ++a * i.x : a++ * i.x;
			Console.WriteLine(z);
		}
	}
}